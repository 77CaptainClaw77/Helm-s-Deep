set ns [new Simulator]
set tracefile [open A4.tr w]
set namfile [open A4.nam w]
$ns namtrace-all $namfile
$ns trace-all $tracefile
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec awk -f A4.awk A4.tr &
    exec nam A4.nam &
    exit 0
}
set n1 [$ns node]
$n1 label "FTP Source"
set n2 [$ns node]
$n2 label "CBR Source"
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
$ns duplex-link $n1 $n3 10Mb 5ms DropTail
$ns duplex-link-op $n1 $n3 orient right-down
$ns duplex-link $n2 $n3 20Mb 5ms DropTail
$ns duplex-link-op $n2 $n3 orient right-up
$ns duplex-link $n3 $n4 20Mb 5ms DropTail
$ns duplex-link-op $n3 $n4 orient right
$ns duplex-link-op $n3 $n4 label "Error Link"
$ns duplex-link $n4 $n5 10Mb 5ms DropTail
$ns duplex-link-op $n4 $n5 orient right-up
$ns duplex-link $n4 $n6 20Mb 5ms DropTail
$ns duplex-link-op $n4 $n6 orient right-down
set error [new ErrorModel]
$ns lossmodel $error $n3 $n4
$error set rate_ 0.2
set ftp_source [new Application/FTP]
set cbr_source [new Application/Traffic/CBR]
set tcp_agent [new Agent/TCP]
$tcp_agent set packetSize_ 1500
set tcpsink_agent [new Agent/TCPSink]
set udp_agent [new Agent/UDP]
$udp_agent set packetSize_ 1500
set udpsink_agent [new Agent/Null]
$ftp_source attach-agent $tcp_agent
$cbr_source attach-agent $udp_agent
$ns attach-agent $n1 $tcp_agent
$ns attach-agent $n2 $udp_agent
$ns attach-agent $n5 $tcpsink_agent
$ns attach-agent $n6 $udpsink_agent
$ns connect $tcp_agent $tcpsink_agent
$ns connect $udp_agent $udpsink_agent
$ns at 0.2 "$ftp_source start"
$ns at 0.2 "$cbr_source start"
$ns at 10.0 "$ftp_source stop"
$ns at 10.0 "$cbr_source stop"
$ns at 10.2 "finish"
$ns run

