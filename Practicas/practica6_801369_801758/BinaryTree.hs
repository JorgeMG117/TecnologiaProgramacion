module BinaryTree where

import Prelude
import Data.List

data Tree t = Empty | Leaf t | Branch t (Tree t) (Tree t) 

empty :: Tree t
empty = Empty

leaf :: x -> Tree x
leaf x = Leaf x

tree :: x -> Tree x -> Tree x -> Tree x
tree x lc rc = Branch x lc rc

size :: Tree x -> Integer
size (Branch _ lc rc) = 1 + size lc + size rc
size (Leaf _)= 1
size Empty = 0

instance Show t => Show (Tree t ) where
    show t = show' t 1
        where
            --show' :: Tree t -> Integer -> String
            show' (Leaf t) _ = (show t)
            show' (Branch t lc rc ) nivel = (show t) ++ "\n" ++ (take (2*nivel) (cycle " ")) ++"|-" ++ (show' lc (nivel+1)) ++ "\n" ++ (take (2*nivel) (cycle " ")) ++ "|-" ++ (show' rc (nivel+1))
            show' (Empty) _ = "<>"


add :: Ord x => Tree x -> x -> Tree x
add (Empty) x = Leaf x
add (Leaf t) x
    | x < t     = Branch t (Leaf x) Empty
    | otherwise = Branch t Empty (Leaf x) 

add (Branch t lc rc) x
    | x < t     = Branch t (add lc x) rc
    | otherwise = Branch t lc (add rc x)

build :: Ord x => [x] -> Tree x
--build (x:xs) = add (build xs) x
build [] = Empty
--build lista = add (build init lista) last lista
build lista = foldl add empty lista


buildBalanced :: Ord x => [x] -> Tree x

buildBalanced lista = buildBalanced' (sort lista)

buildBalanced' :: Ord x => [x] -> Tree x
buildBalanced' [] = Empty
buildBalanced' [x] = Leaf x
buildBalanced' lista  = Branch mid (buildBalanced' left) (buildBalanced' right)
    where 
        (left,mid:right) = splitAt (div (length lista) 2) lista



preorder :: Tree x -> [x] --raiz, izq, der
preorder (Empty) = []
preorder (Leaf t) = [t]
preorder (Branch t lc rc) = [t] ++ (preorder lc) ++ (preorder rc)


postorder :: Tree x -> [x]   --izq, der, raiz
postorder (Empty) = []
postorder (Leaf t) = [t]
postorder (Branch t lc rc) = (postorder lc) ++ (postorder rc) ++ [t]

inorder :: Tree x -> [x] --izq, raiz, der
inorder (Empty) = []
inorder (Leaf t) = [t]
inorder (Branch t lc rc) = (inorder lc) ++ [t] ++ (inorder rc) 



balance :: Ord x => Tree x -> Tree x
balance t = buildBalanced' (inorder t)

between :: Ord x => Tree x -> x -> x -> [x] 
between (Empty) _ _ = []
between (Leaf t) xmin xmax
    | xmin <= t && t <= xmax    = [t]
    | otherwise                 = []
between (Branch t lc rc) xmin xmax  
    | xmin > t                  = between rc xmin xmax
    | xmax < t                  = between lc xmin xmax
    | otherwise                 = between lc xmin xmax ++ [t] ++ between rc xmin xmax





