import FamilyTree

hoy = ABY 2021
ayr = BBY 2021

yo = Person "Juan" ayr

skywalker =
  Node (Person "Shmi" (BBY 72))
  [
    Node (Person "Anakin" (BBY 42))
    [
      Node (Person "Luke" (BBY 19))
      [
        Leaf (Person "Ben" (ABY 26))
      ],
      Node (Person "Leia" (BBY 19))
      [
        Leaf (Person "Ben" (ABY 1)),
        Leaf (Person "Jaina" (ABY 9)),
        Leaf (Person "Jacen" (ABY 9)),
        Leaf (Person "Anakin" (ABY 10))
      ]
    ]
  ]

main = do
  print skywalker
  print (youngest skywalker)
