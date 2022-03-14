-- Graphs
module Main where

import System.CPUTime
import Data.List
import Graph

g :: Graph Int

org = 9
dst = 5
-- org = 7
-- dst = 8

pth = sortOn length (paths g org dst)

main = do
        putStrLn "Go..."
        t0 <- getCPUTime
        putStrLn ("org: " ++ show org)
        putStrLn ("dst: " ++ show dst)
        putStrLn ("nsol: " ++ show (length pth))
        putStrLn "shortest: "
        print $ shortest pth
        putStrLn "lengths: "
        print (map length pth)
        t1 <- getCPUTime
        putStrLn  "...done"
        print $ div (t1-t0) 1000000000

g = Graph verts succ
  where
    verts   = [1..10]

    succ :: Int -> [Int]
    succ  1 = [4,5,6,8]
    succ  2 = [4]
    succ  3 = [4]
    succ  4 = [5]
    succ  5 = [6]
    succ  7 = [6]
    succ  8 = [1,2,7]
    succ  9 = [8,10]
    succ 10 = [2,3]
    succ  _ = []
