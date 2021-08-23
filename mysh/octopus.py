import subprocess

octopusASCII = [
"      ,'''`.",
"     /      \ ",
"     |(@)(@)|",
"     )      (",
"    /,'))((`.\ ",
"   (( ((  )) ))",
"   ) \ `)(' / ( ",
]


def print_octopus(spaces=2):
    print()
    for ol in octopusASCII:
        print(" "*spaces + str(ol))
    print()

def get_ip():
   arg='ip route list'
   try:    
    p=subprocess.Popen(arg,shell=True,stdout=subprocess.PIPE)
    data = p.communicate()
    split_data = data[0].split()
    ipaddr = split_data[split_data.index(b'src')+1].decode("utf-8")
   except:
     ipaddr ="ip.Err"
   #print "ip: " ip
   return ipaddr

# -------------------main -------------------------   
print_octopus()   
print("IP:",get_ip()) 
