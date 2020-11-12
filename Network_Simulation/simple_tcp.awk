BEGIN{
    drop_cnt=0;
}
{
    if($1=="d")
    {
	drop_cnt++;
	printf("%s\t%s\n",$5,$11);
    }
}
END{
    printf("Total number of packets dropped: %d",drop_cnt);
}
