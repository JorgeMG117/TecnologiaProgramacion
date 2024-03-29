import BinaryTree

tree0 = tree "R" (tree "HI" (leaf "NII") (leaf "NID")) (tree "HD" (leaf "NDI") (leaf "NDD"))
tree1a = build [3, 2, 2, 5, 1, 4, 4]
tree1b = build [2, 5, 1, 3, 2, 4, 4]
tree2  = build ["Adolfo","Diego","Juan","Pedro","Tomas"]
tree3  = build [1..6]

main = do
  print $ size tree0
  print tree0
  print $ preorder tree0
  print $ postorder tree0
  print $ inorder tree0

  print "Tree1a:"
  print tree1a
  print "Inorder:"
  print $ inorder tree1a
  print "Balance:"
  print $ balance tree1a
  print "Between:"
  print $ between tree1a 2 4
  print "Tree1b:"
  print tree1b
  print "Inorder:"
  print $ inorder tree1b
  print "Balance:"
  print $ balance tree1b
  print "Between:"
  print $ between tree1b 2 4

  print "Tree2:"
  print tree2
  print $ balance tree2
  print $ inorder.balance $ tree2

  print "Tree3:" 
  print tree3
  print $ balance tree3
