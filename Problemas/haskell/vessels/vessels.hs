-- Vessels
module Main where

import System.CPUTime
import Data.List
import Graph

data Vessels = Vessels Float Float
    deriving (Eq)
instance Show Vessels where
    show (Vessels a b) = show (a,b)

g :: Graph Vessels

org = Vessels 0 0
dst = Vessels 6 13

pth = sortOn length (paths g org dst)

main = do
        putStrLn "Go..."
        t0 <- getCPUTime
        putStrLn ("org: " ++ show org)
        putStrLn ("dst: " ++ show dst)
        putStrLn ("nsol: " ++ show (length pth))
        putStrLn "shortest: "
        mapM print $ shortest pth
        putStrLn "lengths: "
        print (map length pth)
        t1 <- getCPUTime
        putStrLn  "...done"
        print $ div (t1-t0) 1000000000

g = Graph cap succ
  where
    cap = Vessels 20 13

    -- Posibles siguientes estados de las vasijas a partir de uno dado
    succ :: Graph Vessels -> Vessels -> [Vessels]
    succ (Graph (Vessels ca cb) _) o@(Vessels a b)
        = delete o $ nub $ (emp ++ fil ++ dumpab ++ dumpba)
        where
            emp = [ Vessels  0 b, Vessels a  0]
            fil = [ Vessels ca b, Vessels a cb]
            t = a+b
            dumpab
                | (b>=cb)   = []
                | (a<=0)    = []
                | t<=cb     = [Vessels      0  t]
                | t> cb     = [Vessels (t-cb) cb]
                | otherwise = []
            dumpba
                | (a>=ca)   = []
                | b<=0      = []
                | t<=ca     = [Vessels  t      0]
                | t> ca     = [Vessels ca (t-ca)]
                | otherwise = []
