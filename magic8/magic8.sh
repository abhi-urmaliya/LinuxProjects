echo "Welcome to the magic 8 ball program"
echo "Think hard on your question and enter it : "
read a
echo "The magic ball says : "

var=`expr $RANDOM % 20`

sleep 3

insmod magic8mod.ko myint=$var

sleep 3

rmmod magic8mod.ko
