esPrimo :: Integer -> Bool
esPrimo n = [] == [x | x<-[2..(n-1)], n `mod` x == 0] 

-- Solucion facil coste cúbico (dos generadores en goldbach + 1 generador en esPrimo)
goldbach :: Integer -> [(Integer,Integer)]
goldbach n = [(x,y) | x<-[1..(n-1)], y<-[x..(n-1)], esPrimo x, esPrimo y, x+y == n] 

-- Solución menos fácil coste cuadrático (un generadores en goldbach + 1 generador en esPrimo)
goldbach' :: Integer -> [(Integer,Integer)]
goldbach' n = [(x,n-x) | x<-[1..(n `div` 2)], esPrimo x, esPrimo (n-x)] 
