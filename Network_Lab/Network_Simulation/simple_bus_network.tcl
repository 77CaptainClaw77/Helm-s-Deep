set ns [new Simulator]
set tracefile [open simple_bus_network.tr w]
$ns trace-all $tracefile
set namfile [open simple_bus_network.nam w]
$ns namtrace-all $namfile
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec nam simple_bus_network.nam &
    exec awk -f packet_count.awk simple_bus_network.tr &
    exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set lan0 [$ns newLan "$n0 $n1 $n2 $n3 $n4" 0.5Mb 40ms LL Queue/DropTail MAC/Csma/Cd Channel]
set tcp_agent [new Agent/TCP]
$tcp_agent set class_ 1
$ns attach-agent $n0 $tcp_agent
set tcpsink_agent [new Agent/TCPSink]
$ns attach-agent $n4 $tcpsink_agent
$ns connect $tcp_agent $tcpsink_agent
set cbr_src [new Application/Traffic/CBR]
$cbr_src set packetSize_ 500
$cbr_src set interval_ 0.01
$cbr_src attach-agent $tcp_agent
$ns at 0.1 "$cbr_src start"
$ns at 3.0 "$cbr_src stop"
$ns at 3.1 "finish"
$ns run
