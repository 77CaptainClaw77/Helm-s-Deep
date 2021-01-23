set ns [new Simulator]
set namfile [open A5.nam w]
set tracefile [open A5.tr w]
set winfile [open A5.xg w]
$ns trace-all $tracefile
$ns namtrace-all $namfile
proc finish {} {
    global ns namfile winfile tracefile
    $ns flush-trace
    close $tracefile
    close $namfile
    close $winfile
    exec nam A5.nam &
    exec ~/Documents/Xgraph/XGraph4.38_linux64/bin/xgraph A5.xg -title "Congestion Window"  &
    exit 0
}
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
$ns duplex-link $n1 $n2 5Mb 2ms DropTail
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link $n2 $n3 0.5Mb 100ms DropTail
$ns queue-limit $n2 $n3 5
$ns duplex-link-op $n2 $n3 orient right
$ns duplex-link $n3 $n4 5Mb 2ms DropTail
$ns duplex-link-op $n3 $n4 orient right
$ns duplex-link-op $n1 $n2 queuePos 0.5
Agent/TCP set nam_tracevar_ true
Agent/TCP set window_ 20
Agent/TCP set ssthresh_ 20
set tcp_agent [new Agent/TCP]
$tcp_agent set packetSize_ 1500
set tcpsink_agent [new Agent/TCPSink]
set ftp_source [new Application/FTP]
$ftp_source attach-agent $tcp_agent
$ns attach-agent $n1 $tcp_agent
$ns attach-agent $n4 $tcpsink_agent
$ns connect $tcp_agent $tcpsink_agent
$ns add-agent-trace $tcp_agent tcp
$ns monitor-agent-trace $tcp_agent
$tcp_agent tracevar cwnd_
$tcp_agent tracevar ssthresh_
proc plotting {tcp_ag wfile} {
    global ns
    set now [$ns now]
    set cwnd_ [$tcp_ag set cwnd_]
    puts $wfile "$now $cwnd_"
    $ns at [expr $now+0.1] "plotting $tcp_ag $wfile"
}
$ns at 0.2 "$ftp_source start"
$ns at 0.2 "plotting $tcp_agent $winfile"
$ns at 10.0 "$ftp_source stop"
$ns at 10.2 "finish"
$ns run
