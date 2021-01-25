require 'socket'
print "Enter rez\n"
while true
    connect = TCPSocket.open("localhost",8080)
    msg=$stdin.gets
    connect.puts(msg)  #Передача данных на сервер
     #Получение системной информации
    puts connect.gets()  #Получение суммы ВМ
    connect.close
end


