#create simulator object
set ns [new Simulator]
#open network animation file in write mode
set namfile [open simple_tcp.nam w]
#open tracefile in write mode
set tracefile [open simple_tcp.tr w]
#set tracefile to ns and animation file to ns to write data
$ns trace-all $tracefile
$ns namtrace-all $namfile
#procedure to execute on finishing
proc finish {} {
    #declare global variables
    global ns namfile tracefile
    #complete file operations and flush buffer
    $ns flush-trace
    #close files
    close $namfile
    close $tracefile
    #open nam file and run awk script on execution
    #& is used to run the task in background
    exec nam simple_tcp.nam & 
    exec awk -f packet_count.awk simple_tcp.tr &
    #end process
    exit 0
}
#declare nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
#5 node network additions
# set n3 [$ns node]
# set n4 [$ns node]
#set labels for ns
$n0 label "TCP Source"
$n2 label "TCP Sink"
#set links between nodes for 2 node network
$ns duplex-link $n0 $n1 8.0Mb 1ms DropTail
$ns duplex-link $n1 $n2 1.9Mb 2ms DropTail
#links for 5 node network
# $ns duplex-link $n0 $n1 8.0Mb 1ms DropTail
# $ns duplex-link $n1 $n3 7.0Mb 1ms DropTail
# $ns duplex-link $n3 $n4 2.0Mb 1ms DropTail
# $ns duplex-link $n4 $n2 3.0Mb 1ms DropTail
# #set queue limit - optional, can be used to simulate packet drop
$ns queue-limit $n1 $n2 15
#queue limits for 5 node network
# $ns queue-limit $n3 $n4 5
#declare source and sink agents for TCP
set tcp_agent [new Agent/TCP]
set tcpsink_agent [new Agent/TCPSink]
#set application layer traffic source
set ftp_src [new Application/FTP]
#Attach agents
$ns attach-agent $n0 $tcp_agent
$ns attach-agent $n2 $tcpsink_agent
$ftp_src attach-agent $tcp_agent
#connect the agents
$ns connect $tcp_agent $tcpsink_agent
#start and stop the traffic
$ns at 0.2 "$ftp_src start"
$ns at 3.0 "$ftp_src stop"
#call finish procedure to end
$ns at 3.1 "finish"
#run simulation
$ns run 
