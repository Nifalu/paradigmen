-- Swap the values of the first and last element in a list
swapFirstAndLast :: [a] -> [a]
swapFirstAndLast [] = []
swapFirstAndLast [x] = [x]
swapFirstAndLast xs = last xs : tail (init xs) ++ [head xs]

-- Return, as a Boolean, whether two consecutive elements in a list are the same.
containsEqualConsec :: Eq a => [a] -> Bool
containsEqualConsec [] = False
containsEqualConsec [_] = False
containsEqualConsec (x:y:xs) = x == y || containsEqualConsec(y:xs)

-- Return a list containing all divisors of a given positive integer.
getDivisors :: Int -> [Int]
getDivisors n = [x | x <- [1..n], n `mod` x == 0] 

-- Remove all odd numbers from a list.
removeOdd :: [Int] -> [Int]
removeOdd = filter even

-- Calculate the mean of the even numbers in a list.
calcMean :: [Int] -> Int
calcMean xs = sum (filter even xs) `div` length(filter even xs)

-- Generate a list of tuples (n, s) where 0 <= n <= 30 and where s = n^2 .
generateTupleList :: () -> [(Int, Int)]
generateTupleList () = [(x,x^2) | x <- [1..30]]

-- Take two positive integers and return a list containing their shared prime factors.
sharedPrimes :: Int -> Int -> [Int]
sharedPrimes n t = [ y | y <- [2..max n t], n `mod` y == 0, t `mod` y == 0, [x | x <- [1..y], y `mod` x == 0] == [1, y]]

-- Return an infinite list of natural even numbers
infEvenN :: [Int]
infEvenN = [2,4..]

-- tuple with infEvenN and infEvenN * 2
tupleList :: [Int] -> [(Int, Int)]
tupleList n = [(x, x*2) | x <- n]

-- n*n < n list
anotherList :: [(Int, Int)] -> Int -> [(Int, Int)]
anotherList n s = takeWhile (\(_, y) -> y < s) n

-- ackermann three arguments
ackermann :: Int -> Int -> Int -> Int
ackermann m n 0 = m + n
ackermann m 0 1 = 0
ackermann m 0 2 = 1
ackermann m 0 p | p > 2 = m
ackermann m n p | n > 0, p > 0 = ackermann m (ackermann m (n-1) p) (p-1)

-- ackermann list
ackermannList :: [Int] -> [Int]
ackermannList [] = [13]
ackermannList [x] = [ackermann x 0 3]
ackermannList [x,y] = [ackermann x y 0]
ackermannList [x,y,z] = [ackermann x y z]
ackermannList (x:y:z:xs) = ackermann x y z : ackermannList xs

-- sorted
sorted :: (Ord a) => [a] -> Bool
sorted [] = True
sorted [_] = True
sorted (x:y:ys) = x <= y && sorted (y:ys)

-- mergesort
mergesort' :: (Ord a) => [a] -> [a]
mergesort' [] = []
mergesort' [x] = [x]
mergesort' xs = merge (mergesort' left) (mergesort' right)
    where
        (left, right) = splitAt(length xs `div` 2) xs

        merge :: (Ord a) => [a] -> [a] -> [a]
        merge [] r = r
        merge l [] = l
        merge (l:ls) (r:rs)
            | last (l:ls) <= r = (l:ls)++(r:rs)
            | last (r:rs) <= l = (r:rs)++(l:ls) 
            | l <= r    = l : merge ls (r:rs) 
            | otherwise = r : merge (l:ls) rs 

mergesort :: (Ord a) => [a] -> [a]
mergesort xs 
    | sorted xs = xs
    | otherwise = mergesort' xs

bubbleSort :: (Ord a) => [a] -> [a]
bubbleSort xs = go xs
  where
    go :: (Ord a) => [a] -> [a]
    go xs
      | swapped   = go passResult
      | otherwise = xs
      where (swapped, passResult) = onePass xs

    onePass :: (Ord a) => [a] -> (Bool, [a])
    onePass [] = (False, [])
    onePass [x] = (False, [x])
    onePass (x:y:ys)
      | x <= y    = (swappedTail, x : sortedTail)
      | otherwise = (True, y : sortedTail')
      where
        (swappedTail, sortedTail) = onePass (y : ys)
        (swappedTail', sortedTail') = onePass (x : ys)

myfilter :: (a -> Bool) -> [a] -> [a]
myfilter _ [] = []
myfilter p (x:xs)
  | p x = x : myfilter p xs -- if true, include and go next
  | otherwise = myfilter p xs -- if false, ignore and go next

mymap :: (a -> b) -> [a] -> [b]
mymap _ [] = [] -- if empty return empty
mymap f (x:xs) = f x : mymap f xs -- apply f and go next

bmi :: Double -> Double -> Double
bmi m l = m / (l*l) * 10000

isBad :: Double -> Bool
isBad x = x > 25 || x < 18.5

roundToOneDec :: Double -> Double
roundToOneDec x = fromIntegral (round (x*10))/10

bmilists :: [Double] -> [Double] -> ([Double], [Int])
bmilists m l = (bmis,badindex)
  where
  bmis = mymap roundToOneDec (zipWith bmi m l)
  badindex = [x | x <- [0..length bmis-1], isBad (bmis !! x)]




main :: IO ()
main = do

  putStrLn "------------------------------------"
  putStrLn "QUESTION 1"
  putStrLn "------------------------------------"

  putStrLn "Question 1a: Swap first and last Element in a List"
  putStrLn "From list before: [1,2,3,4,5] to list after swap:"
  print (swapFirstAndLast [1,2,3,4,5])
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1b: Return true when two consecutive elements are equal"
  putStrLn "List [1,2,3,3,4,5] equals:"
  print (containsEqualConsec [1,2,3,3,4,5])
  putStrLn "List [1,2,3] equals:"
  print (containsEqualConsec [1,2,3])
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1c: Return a list containg all divisors of a given positive integer."
  putStrLn "Divisors of 42:"
  print (getDivisors 42)
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1d: Remove all odd numbers from a list."
  putStrLn "Remove odds from [1,2,3,4,5,6,7,8,9,10]:"
  print (removeOdd [1,2,3,4,5,6,7,8,9,10])
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1e: Calculate the mean of the even numbers in a list"
  putStrLn "Calculate mean of the even numbers in [1,2,3,4,5,6,7,8,9,10]:"
  print (calcMean [1,2,3,4,5,6,7,8,9,10])
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1f: Generate a list of tuples (n, s) where 0 ≤ n ≤ 30 and where s = n2 "
  print (generateTupleList())
  putStrLn "------------------------------------"
  putStrLn ""

  putStrLn "Question 1g: Take two positive integers and return a list containing their shared prime factors."
  putStrLn "Shared prime factors of 42 and 27"
  print (sharedPrimes 42 27)
  putStrLn "------------------------------------"
  putStrLn ""


  putStrLn "------------------------------------"
  putStrLn "QUESTION 5"
  putStrLn "------------------------------------"

  let heights = [172, 195, 157, 144, 165, 191, 183, 194, 185, 194, 183, 194, 186, 152, 156, 163, 179, 164, 186, 181, 158, 181, 155, 197, 150, 166, 179, 153, 142, 154, 162, 156, 149, 166, 148, 195, 198, 152, 167, 197, 157, 144, 147, 159, 198, 149, 179, 183, 156, 175, 157]
  let weights = [97, 95, 53, 40, 46, 73, 68, 67, 69, 62, 99, 89, 77, 94, 100, 63, 75, 44, 81, 96, 63, 99, 64, 88, 77, 104, 50, 97, 81, 84, 66, 78, 72, 93, 42, 93, 94, 58, 48, 94, 71, 47, 49, 57, 93, 71, 106, 63, 81, 95]

  print (bmilists weights heights)
  putStrLn "------------------------------------"
  putStrLn ""
