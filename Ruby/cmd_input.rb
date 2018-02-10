#using functions

def printTrue()
	puts"Program executed correctly"
end

def printFalse()
	puts"Program executed incorrectly"
end

def Addition(a,b)
	result = a + b
	return result
end


puts "Program  start"
#printSth()
puts "Enter 2 numbers"
a = gets.chomp().to_i
b = gets.chomp().to_i
result = Addition(a,b)
puts "result = #{result}"
if result = a + b
	printTrue()
else
	printFalse()
end
