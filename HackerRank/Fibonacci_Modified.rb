#
#  Author: Ganesh Kudva
#  https://www.hackerrank.com/challenges/fibonacci-modified
#

series = Array.new(100){0}  
series[1], series[2], index = gets().strip.split(" ").map{|x|x.to_i}  
(3..lim).each do |num|  
	series[num] = series[num-1]**2 + series[num-2]    
end  
puts series[index]
