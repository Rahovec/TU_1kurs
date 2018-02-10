#USER INPUT aka scanf n shit

puts "Tell me name, age and city, blyat:"
name = gets.chomp() #.chomp ne hvashta entera sled kato vkaram infoto
age = gets.chomp().to_f #.to_i pravi promenlivata ot string v int
city = gets.chomp()
puts "#{name} #{age} #{city}"
