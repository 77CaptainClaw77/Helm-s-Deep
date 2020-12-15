set ns [new Simulator]
set tracefile [open congestion_window.tr w]
$ns trace-all $tracefile
set namfile [open congestion_window.nam w]
$ns namtrace-all $namfile
#new window file
set winfile [open window_file w]
proc finish {} {
    global ns tracefile namfile winfile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec nam congestion_window.nam &
    exec awk -f packet_count.awk congestion_window.tr &
    exec /home/kumarguru/Documents/XGraph4.38_linux64/bin/xgraph window_file &
    exit 0
}
proc plotting {tcpsource winfile} {
    global ns
    set now [$ns now]
    set cwnd [$tcpsource set cwnd_]
    puts $winfile "$now $cwnd"
    $ns at [expr $now+0.1] "plotting $tcpsource $winfile"
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns duplex-link $n0 $n1 5Mb 20ms DropTail
$ns queue-limit $n0 $n1 50
$ns duplex-link $n1 $n2 0.5Mb 100ms DropTail
$ns queue-limit $n1 $n2 5
$ns duplex-link $n2 $n3 5Mb 20ms DropTail
$ns queue-limit $n2 $n3 50
$ns duplex-link-op $n1 $n2 queuePos 0.5
$ns duplex-link-op $n0 $n1 orient right
$ns duplex-link-op $n1 $n2 orient right
$ns duplex-link-op $n2 $n3 orient right
Agent/TCP set nam_tracevar_ true
Agent/TCP set window_ 20
Agent/TCP set ssthresh_ 20
set tcpsource [new Agent/TCP]
$ns attach-agent $n0 $tcpsource
set tcpsink [new Agent/TCPSink]
$ns attach-agent $n3 $tcpsink
$ns connect $tcpsource $tcpsink
$tcpsource set packetSize_ 1500
set ftp_src [new Application/FTP]
$ftp_src attach-agent $tcpsource
$ns at 0.1 "$ftp_src start"
$ns at 0.1 "plotting $tcpsource $winfile"
$ns at 8.0 "$ftp_src stop"
$ns add-agent-trace $tcpsource tcp
$ns monitor-agent-trace $tcpsource
$tcpsource tracevar cwnd_
$tcpsource tracevar ssthresh_
$ns at 8.1 "finish"
$ns run
