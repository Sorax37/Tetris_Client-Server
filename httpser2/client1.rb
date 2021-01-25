require 'socket'
print "Enter rez1 \n"
while true
connect = TCPSocket.open("127.0.0.1",8080)
msg=$stdin.gets
connect.puts(msg)  #Передача данных на сервер
msg=$stdin.gets
 #Получение системной информации
puts connect.gets()
connect.close
end


