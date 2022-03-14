gregoryleibnitz :: [Double]
gregoryleibnitz = map mul $ zipWith (/) (map num [0..]) (map den [0..])
    where
        mul x = 4*x
        num x = (-1)^x
        den x = 2*x+1
        
gregoryleibnitz' :: [Double]
gregoryleibnitz' = zipWith (/) (cycle [4,-4]) [1,3..]


approxPi :: Int -> Double
approxPi n = sum $ take n gregoryleibnitz

approxPiTol :: Double -> Double
approxPiTol tol = sum $ takeWhile good gregoryleibnitz
    where
        good x = (abs x) > tol 
