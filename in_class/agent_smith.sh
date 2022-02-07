ln -s "me_me"   #symbolic links
ln -s "me" 
ln -s "me_too" 

chmod  u=rw  "agent_smith.sh" #110 000 000

ls -lg > "smith_list.txt"   #make the file and fill it with the contents

ls -a|wc -l ##this is printing out the number of files!!!  
