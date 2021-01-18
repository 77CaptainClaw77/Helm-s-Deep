BEGIN{
    tcp_size=0
    udp_size=0
    tcp_last_time=0
    udp_last_time=0
}
{
    if($1=="r" && $3=="3" && $4="4" && $5=="tcp"){
	tcp_size+=$6
	tcp_last_time=$2
    }
    if($1=="r" && $3=="1" && $4="2"){
	udp_size+=$6
	udp_last_time=$2
    }
}
END{
    printf("TCP Throughput: %f Mbps\n",(tcp_size/tcp_last_time)*(8/1000000));
    printf("UDP Throughput: %f Mbps\n",(udp_size/udp_last_time)*(8/1000000));
}
