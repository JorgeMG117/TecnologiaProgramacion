module FamilyTree where

data Year = BBY Word | ABY Word deriving Eq

instance Show Year where
  show (BBY y) = (show y) ++ ".BBY"
  show (ABY y) = (show y) ++ ".ABY"

instance Ord Year where
  (BBY _) <= (ABY _) = True
  (ABY _) <= (BBY _) = False
  (BBY x) <= (BBY y) = x >  y
  (ABY x) <= (ABY y) = x <= y

data Person = Person String Year deriving Eq

instance Ord(Person) where
  (Person _ pd) <= (Person _ qd) = pd > qd

instance Show(Person) where
  show (Person n bd) = (show n) ++ "(" ++ (show bd) ++ ")"

data FamilyTree = Empty | Leaf Person | Node Person [FamilyTree]
                  deriving Show

youngest :: FamilyTree -> String

youngest t = name
  where
    (Person name _) = youngest_tree t

youngest_tree :: FamilyTree -> Person
youngest_tree Empty        = undefined
youngest_tree (Leaf p)     = p
youngest_tree (Node p cld) = min p (youngest_list cld)

youngest_list :: [FamilyTree] -> Person
youngest_list []     = undefined
youngest_list [x]    = youngest_tree x
youngest_list (x:xs) = min (youngest_tree x) (youngest_list xs)
