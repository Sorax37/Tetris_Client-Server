require 'socket'
require 'csv'
require 'json'
include Socket::Constants

class Server
	@path = 'record.txt'
	def self.main
	  fileRead
      server = TCPServer.new('127.0.0.1',8080)
	  puts 'server'
	  while true
		session=server.accept
		Thread.start(session) do |connection|
		  connection.print @record_table.sort_by{ |key, value| value}.reverse![0..9].to_h
		  request = connection.gets.split(/ /) #Получение данных и преобразование их в массив
		  puts request
		  if request.size==2
		    puts request
		    record(request)
		    fileWrite
			puts @record_table
		  elsif request.size == 1
			connection.print @record_table.sort_by{ |key, value| value}.reverse![0..9].to_h
		  end
	      connection.close
	    end
	  end
	end

	def self.record(request)
		if @record_table.has_key? request[0]
		  if @record_table[request[0]]<request[1].to_i
			 @record_table[request[0]]=request[1].to_i
		  end
		elsif 
			@record_table[request[0]]=request[1].to_i
		end
		@record_table
	end

	def self.fileRead
	  if File.file?(@path)
	    buffer = File.open(@path, 'r').read
	    @record_table = JSON.parse(buffer)
	  else
		@record_table = {}
	  end
		puts @record_table
	end

	def self.fileWrite
	  stdout = File.open(@path, 'w') {|f| f.write(@record_table.to_json)}	
	end
main
end