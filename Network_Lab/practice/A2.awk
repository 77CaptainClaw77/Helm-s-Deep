BEGIN{
    udp_cnt=0;
    tcp_cnt=0;
    udp_drop=0;
    tcp_drop=0;
}
{
    if($5=="tcp"){
	tcp_cnt++;
	if($1=="d"){
	    tcp_drop++;
	    printf("%s\t%s\n",$5,$11);
	}
    }
    if($5=="cbr"){
	udp_cnt++;
	if($1=="d"){
	    udp_drop++;
	    printf("%s\t%s\n",$5,$11);
	}
    }
}
END{
    printf("Number of TCP packets: %d\n",tcp_cnt);
    printf("Number of UDP packets: %d\n",udp_cnt);
    printf("Number of TCP packets dropped: %d\n",tcp_drop);
    printf("Number of UDP packets dropped: %d\n",udp_drop);
    printf("TCP packet delivery fraction: %f\n",(tcp_cnt-tcp_drop)/tcp_cnt);
    printf("UDP packet delivery fraction: %f\n",(udp_cnt-udp_drop)/udp_cnt);
}
