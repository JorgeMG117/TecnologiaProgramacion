-- Utilidades
module Graph where

import Data.List

data Graph v = Graph [v] (v->[v])

vertices :: Graph v -> [v]
vertices (Graph vs _) = vs

neigbours :: Graph v -> v -> [v]
neigbours (Graph _ suc) = suc

paths :: Eq v => Graph v -> v -> v -> [[v]]
paths g o d = pathsCond g o (== d)

pathsCond :: Eq v => Graph v -> v -> (v -> Bool) -> [[v]]
pathsCond g o t = pathsCond' g o t []

pathsCond' :: Eq v => Graph v -> v -> (v -> Bool) -> [v] -> [[v]]

pathsCond' g@(Graph _ suc) o tst vis
    | tst o     = [[o]]
    | otherwise = [ o:pth | nxt <- (suc o)\\vis,
                            pth <- pathsCond' g nxt tst (vis++[o])]

{-
pathsCond' g@(Graph vs suc) o tst vis
    | tst o     = [[o]]
    | otherwise = [o:pth | pth <- (concat (map (\nxt -> pathsCond' g nxt tst (o:vis)) ((suc o)\\vis) ))]
-}

-- Lista de las soluciones mas cortas
-- supone que estan ordenadas
shortest :: [[v]] -> [[v]]
shortest [] = []
shortest [x] = [x]
shortest (x:xs) = x:(takeWhile ((== l).length) xs)
    where
        l = length x
