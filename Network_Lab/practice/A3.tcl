set ns [new Simulator]
set namfile [open A3.nam w]
set tracefile [open A3.tr w]
$ns trace-all $tracefile
$ns namtrace-all $namfile
proc finish {} {
    global ns namfile tracefile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec awk -f A3_ftp.awk A3.tr | tee A3_ftp.xg &
    exec awk -f A3_telnet.awk A3.tr | tee A3_telnet.xg &
    exec ~/Documents/Xgraph/XGraph4.38_linux64/bin/xgraph A3_ftp.xg -title FTP_Plot &
    exec ~/Documents/Xgraph/XGraph4.38_linux64/bin/xgraph A3_telnet.xg -title Telnet_Plot &
    exec nam A3.nam &
    exit 0
}
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
$ns duplex-link $n1 $n3 1Mb 10ms DropTail
$ns queue-limit $n1 $n3 15
$ns duplex-link $n2 $n3 1Mb 10ms DropTail
$ns queue-limit $n2 $n3 15
$ns duplex-link $n3 $n4 0.5Mb 10ms DropTail
$ns queue-limit $n3 $n4 15
$ns duplex-link $n4 $n5 1Mb 10ms DropTail
$ns queue-limit $n4 $n5 15
$ns duplex-link $n4 $n6 1Mb 10ms DropTail
$ns queue-limit $n4 $n6 15
#-45 is same as right-down 45=right up 135=left up -135=left down right=0 left=180
$ns duplex-link-op $n1 $n3 orient right-down 
$ns duplex-link-op $n2 $n3 orient right-up
$ns duplex-link-op $n3 $n4 orient right
$ns duplex-link-op $n4 $n5 orient right-up
$ns duplex-link-op $n4 $n6 orient right-down
$n1 label "FTP source"
$n2 label "Telnet source"
set ftp_source [new Application/FTP]
$ftp_source set packetSize_ 1500
set telnet_source [new Application/Telnet]
$telnet_source set packetSize_ 1500
set tcp_agent_A [new Agent/TCP]
set tcp_agent_B [new Agent/TCP]
set tcpsink_agent_A [new Agent/TCPSink]
set tcpsink_agent_B [new Agent/TCPSink]
$ftp_source attach-agent $tcp_agent_A
$telnet_source attach-agent $tcp_agent_B
$ns attach-agent $n1 $tcp_agent_A
$ns attach-agent $n2 $tcp_agent_B
$ns attach-agent $n5 $tcpsink_agent_A
$ns attach-agent $n6 $tcpsink_agent_B
$ns connect $tcp_agent_A $tcpsink_agent_A
$ns connect $tcp_agent_B $tcpsink_agent_B
$ns at 0.2 "$ftp_source start"
$ns at 0.2 "$telnet_source start"
$ns at 10.0 "$ftp_source stop"
$ns at 10.0 "$telnet_source stop"
$ns at 10.2 "finish"
$ns run
