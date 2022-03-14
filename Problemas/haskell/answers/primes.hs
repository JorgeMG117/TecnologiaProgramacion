module Main where

import System.CPUTime

main = do
	timedRun primes
	timedRun primes'
	timedRun primes''

timedRun :: [Integer] -> IO ()
timedRun f = do
	t0 <- getCPUTime
	print $ last (take 1000 f)
	t1 <- getCPUTime
	putStr "Time: "
	print $ div (t1-t0) 1000000000

primes    = [ x | x <- [1..], all ((/= 0).rem x) [2..x-1] ]

primes'   = [ x | x <- [1..], all ((/= 0).rem x) [2..(round.sqrt.fromInteger) x] ]

primes''  = 1 : sieve [3..]
	where
		sieve [] = []
		sieve (p:xs) = p : sieve [x | x<-xs, mod x p /= 0]

