Class A
A instproc sayhello {} {
    $self instvar num
    puts "A says $num"
}
Class B -superclass A
B instproc sayhello {} {
    $self instvar num
    puts "B says $num"
}
puts "HELLO WORLD"
set objA [new A]
set objB [new B]
$objA set num 100
$objB set num -5
$objA sayhello
$objB sayhello

