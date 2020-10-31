netfilter-test  
=====  

syntax : netfilter-test \<host\>  
sample : netfilter-test test.gilgil.net  

## example
$ sudo ./netfilter-test test.gilgil.net  

run-parts: executing /usr/share/netfilter-persistent/plugins.d/15-ip4tables save  
run-parts: executing /usr/share/netfilter-persistent/plugins.d/25-ip6tables save    
opening library handle  
unbinding existing nf_queue handler for AF_INET (if any)  
binding nfnetlink_queue as nf_queue handler for AF_INET  
binding this socket to queue '0'  
setting copy_packet mode  

...  

pkt received  
IP packet_len=52  
pkt received  
IP packet_len=52  
pkt received  
IP packet_len=378   
Host: test.gilgil.net  
Matches drop target, packet dropped  
pkt received  
IP packet_len=378  
Host: test.gilgil.net  
Matches drop target, packet dropped   

...

^CRestoring Iptable rules  
run-parts: executing /usr/share/netfilter-persistent/plugins.d/15-ip4tables start  
run-parts: executing /usr/share/netfilter-persistent/plugins.d/25-ip6tables start  
Terminating Firewall  
