set ns [new Simulator]
set namfile [open A2.nam w]
set tracefile [open A2.tr w]
$ns trace-all $tracefile
$ns namtrace-all $namfile
proc finish {} {
    global ns namfile tracefile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec nam A2.nam &
    exec awk -f A2.awk A2.tr &
    exit 0
}
set s1 [$ns node]
set s2 [$ns node]
set s3 [$ns node]
set s4 [$ns node]
set r1 [$ns node]
set r2 [$ns node]
$s1 label "TCP Source"
$s2 label "UDP Source"
$s3 label "UDP Sink"
$s4 label "TCP Sink"
$ns duplex-link $s1 $r1 1Mb 10ms DropTail
$ns duplex-link $s2 $r1 1Mb 10ms DropTail
$ns duplex-link $r1 $r2 0.2Mb 10ms DropTail
$ns duplex-link $r2 $s3 1Mb 10ms DropTail
$ns duplex-link $r2 $s4 1Mb 10ms DropTail
#additional params
# $ns queue-limit $r1 $r2 5
# $ns queue-limit $s2 $r1 15
set tcp_agent [new Agent/TCP]
set tcpsink_agent [new Agent/TCPSink]
set udp_agent [new Agent/UDP]
set udpsink_agent [new Agent/Null]
set ftp_source [new Application/FTP]
set cbr_source [new Application/Traffic/CBR]
$ftp_source attach-agent $tcp_agent
$cbr_source attach-agent $udp_agent
$ns attach-agent $s1 $tcp_agent
$ns attach-agent $s2 $udp_agent
$ns attach-agent $s3 $udpsink_agent
$ns attach-agent $s4 $tcpsink_agent
$ns connect $tcp_agent $tcpsink_agent
$ns connect $udp_agent $udpsink_agent
$ns at 0.2 "$ftp_source start"
$ns at 0.2 "$cbr_source start"
$ns at 3.0 "$ftp_source stop"
$ns at 3.0 "$cbr_source stop"
$ns at 3.2 "finish"
$ns run
