set ns [new Simulator]
set tracefile [open ping_message.tr w]
$ns trace-all $tracefile
set namfile [open ping_message.nam w]
$ns namtrace-all $namfile
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $namfile
    close $tracefile
    exec nam ping_message.nam &
    exec awk -f packet_count.awk ping_message.tr &
    exit 0
}

Agent/Ping instproc recv { from rtt } {
    $self instvar node_
    puts "node [$node_ id] received from $from with round trip time $rtt"
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n1 5Mb 20ms DropTail
$ns duplex-link $n0 $n2 5Mb 20ms DropTail
$ns duplex-link $n1 $n3 5Mb 20ms DropTail
$ns duplex-link $n1 $n5 5Mb 20ms DropTail
$ns duplex-link $n2 $n5 5Mb 20ms DropTail
$ns duplex-link $n2 $n3 5Mb 20ms DropTail
$ns duplex-link $n3 $n4 5Mb 20ms DropTail

set ping_agent0 [new Agent/Ping]
set ping_agent1 [new Agent/Ping]
set ping_agent2 [new Agent/Ping]
set ping_agent3 [new Agent/Ping]
set ping_agent4 [new Agent/Ping]
set ping_agent5 [new Agent/Ping]

$ping_agent0 set packetSize_ 50000
$ping_agent0 set interval_ 0.00001
$ping_agent1 set packetSize_ 30000
$ping_agent1 set interval_ 0.00001
$ping_agent2 set packetSize_ 41000
$ping_agent2 set interval_ 0.00001

$ns attach-agent $n0 $ping_agent0
$ns attach-agent $n1 $ping_agent1
$ns attach-agent $n2 $ping_agent2
$ns attach-agent $n3 $ping_agent3
$ns attach-agent $n4 $ping_agent4
$ns attach-agent $n5 $ping_agent5

$ns queue-limit $n0 $n1 3
$ns queue-limit $n1 $n3 2
$ns queue-limit $n2 $n5 7

$ns connect $ping_agent0 $ping_agent3
$ns connect $ping_agent1 $ping_agent4
$ns connect $ping_agent2 $ping_agent5

for { set i 0 } { $i<2 } { set i [expr {$i+0.1}] } {
    $ns at $i "$ping_agent0 send"
    $ns at $i "$ping_agent1 send"
    $ns at $i "$ping_agent2 send"
}

$ns at 2.0 "finish"
$ns run
