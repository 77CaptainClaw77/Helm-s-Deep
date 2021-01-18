BEGIN{
    packet_size_sum=0;
}
{
    if($1=="r" && $3=="0"){
	packet_size_sum+=$6;
	printf("%f\t%f\n",packet_size_sum/$6,$2);
    }
}
END{    
}
