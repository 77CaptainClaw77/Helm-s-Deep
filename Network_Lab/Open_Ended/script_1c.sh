#!/bin/bash
echo "Starting wireshark live capture..."
filename="capture"
for word in $(date "+%F %T"); do
    filename+="_$word"
done
filename+=".pcap"
tshark -q -i wlp2s0 -w $filename &
tshark_pid=$!
sleep 3
echo "Sending request...." 
curl -s "http://gaia.cs.umass.edu/wireshark-labs/HTTP-wireshark-file3.html"
kill $tshark_pid
#tshark -r $filename -Y http.request.method=="GET"
#tshark -r $filename -z http,stat -z
tshark -r $filename -z "io,stat,0,COUNT(http.request.method)http.request.method=="GET""
#get_request_count=
