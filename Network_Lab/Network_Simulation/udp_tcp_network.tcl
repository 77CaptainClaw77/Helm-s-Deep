set ns [new Simulator]
#open tracefile in write mode
set tracefile [open udp_tcp_network.tr w]
$ns trace-all $tracefile
#open network animation file in write mode
set namfile [open udp_tcp_network.nam w]
$ns namtrace-all $namfile
#procedure to execute on finishing
proc finish {} {
    #declare global variables
    global ns namfile tracefile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec nam udp_tcp_network.nam &
    exec awk -f packet_count.awk udp_tcp_network.tr &
    exit 0
}
set s1 [$ns node]
set s2 [$ns node]
set r1 [$ns node]
set r2 [$ns node]
set s4 [$ns node]
set s3 [$ns node]
$s1 label "TCP Source(s1)"
$s2 label "UDP Source(s2)"
$r1 label "r1"
$r2 label "r2"
$s4 label "TCP Sink(s4)"
$s3 label "UDP Source(s3)"
$ns duplex-link $s1 $r1 1.0Mb 10ms DropTail
$ns duplex-link $s2 $r1 1.0Mb 10ms DropTail
$ns duplex-link $r1 $r2 0.8Mb 10ms DropTail
$ns duplex-link $r2 $s4 1.0Mb 10ms DropTail
$ns duplex-link $r2 $s3 1.0Mb 10ms DropTail
set tcp_agent [new Agent/TCP]
set tcpsink_agent [new Agent/TCPSink]
set udp_agent [new Agent/UDP]
set null_agent [new Agent/Null]
set ftp_src [new Application/FTP]
set cbr_src [new Application/Traffic/CBR]
$ftp_src attach-agent $tcp_agent
$cbr_src attach-agent $udp_agent
$ns attach-agent $s1 $tcp_agent
$ns attach-agent $s2 $udp_agent
$ns attach-agent $s4 $tcpsink_agent
$ns attach-agent $s3 $null_agent
$ns connect $tcp_agent $tcpsink_agent
$ns connect $udp_agent $null_agent
$ns at 0.1 "$ftp_src start"
$ns at 0.1 "$cbr_src start"
$ns at 3.0 "$ftp_src stop"
$ns at 3.0 "$cbr_src stop"
$ns at 3.1 "finish"
$ns run
