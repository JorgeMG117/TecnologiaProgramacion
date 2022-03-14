module Lysystem where
    
import Turtle
import Data.Char

tplot :: Turtle -> String -> [Position]
tplot turtle (x:xs) = [pos turtle] ++ tplot turtleAct xs
  where
    turtleAct = tplotAx turtle x

tplot turtle [] = [pos turtle]
    
tplotAx :: Turtle -> Char -> Turtle
tplotAx turtle '>' = moveTurtle turtle Forward
tplotAx turtle '+' = moveTurtle turtle TurnRight
tplotAx turtle '-' = moveTurtle turtle TurnLeft
tplotAx turtle x 
    | isUpper x = moveTurtle turtle Forward
    | otherwise = turtle


pos :: Turtle -> Position
pos (_,_,posicion,_) = posicion

rulesKoch :: Char -> String
rulesKoch 'F' = "F+F--F+F"
rulesKoch x   = [x]

rulesGosper :: Char -> String
rulesGosper 'F' = "F-G--G+F++FF+G-"
rulesGosper 'G' = "+F-GG--G-F++F+G"
rulesGosper x   = [x]

rulesGil:: Char -> String
rulesGil 'f' = "-g>+f>f+>g-"
rulesGil 'g' = "+f>-g>g->f+"
rulesGil x   = [x]

lysystem :: (Char -> String) -> String -> Int -> String
lysystem _ axioma 0 = axioma
lysystem rules (x:xs) num = lysystem rules (rules x) (num-1) ++ lysystem rules xs num
lysystem _ [] _ = []