combine :: Int -> [a] -> [[a]]
combine 0      _ = [[]]
-- combine 1      l = map (\x -> [x]) l   -- Este caso ocurre combinando lineas 2 y 5
combine _     [] = []
combine n (x:xs) = map (poner x) (combine (n-1) xs) ++ combine n xs
    where
        poner x l = x:l


-- combine n (x:xs) = map (\l -> x:l) (combine (n-1) xs) ++ combine n xs
-- combine n (x:xs) = map (x:) (combine (n-1) xs) ++ combine n xs
-- combine n (x:xs) = [x:l | l <- combine (n-1) xs] ++ combine n xs

