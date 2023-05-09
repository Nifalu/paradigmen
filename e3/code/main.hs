-- Swap the values of the first and last element in a list
swap_first_and_last :: [a] -> [a]
swap_first_and_last [] = []
swap_first_and_last [x] = [x]
swap_first_and_last xs = last xs : tail (init xs) ++ [head xs]

-- Return, as a Boolean, whether two consecutive elements in a list are the same.
contains_equal_consec :: Eq a => [a] -> Bool
contains_equal_consec [] = False
contains_equal_consec [_] = False
contains_equal_consec (x:y:xs) = x == y || contains_equal_consec(y:xs)

-- Return a list containing all divisors of a given positive integer.
getDivisors :: Int -> [Int]
getDivisors n = [x | x <- [1..n], n `mod` x == 0] 

-- Remove all odd numbers from a list.
removeOdd :: [Int] -> [Int]
removeOdd xs = filter even xs

-- Calculate the mean of the even numbers in a list.
calcMean :: [Int] -> Int
calcMean xs = (sum (filter even xs)) `div` (length(filter even xs))

-- Generate a list of tuples (n, s) where 0 <= n <= 30 and where s = n^2 .
generateTupleList :: () -> [(Int, Int)]
generateTupleList () = [(x,x^2) | x <- [1..30]]

-- Take two positive integers and return a list containing their shared prime factors.
sharedPrimes :: Int -> Int -> [Int]
--sharedPrimes n t = [ y | y <- [2..max n t], [x | x <- [1..y], y `mod` x == 0, n `mod` y == 0, t `mod` y == 0] == [1, y]]
sharedPrimes n t = [ y | y <- [2..max n t], n `mod` y == 0, t `mod` y == 0, [x | x <- [1..y], y `mod` x == 0] == [1, y]]

-- Return an infinite list of natural even numbers
infEvenN :: [Int]
infEvenN = [2,4..]

-- tuple with infEvenN and infEvenN * 2
zipList :: [Int] -> [(Int, Int)]
zipList n = [(x, x*2) | x <- n]

-- n^2 < n list
-- let zippedlist = zipList infEvenN needs to be called first
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
mergesort :: (Ord a) => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort (x:xs) = merge (mergesort(left)) (mergesort(right))
    where
        (left, right) = splitAt(length (x:xs) `div` 2) (x:xs)

        merge :: (Ord a) => [a] -> [a] -> [a]
        merge [] r = r
        merge l [] = l
        merge (l:ls) (r:rs)
            | l <= r    = l : merge ls (r:rs) -- If x is smaller or equal, put x first and continue with the rest of xs
            | otherwise = r : merge (l:ls) rs -- If y is smaller, put y first and continue with the rest of ys


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
myfilter p (x:xs)
  | p x = x : myfilter p xs -- if true, include and go next
  | otherwise = myfilter p xs -- if false, ignore and go next


mymap :: (a -> b) -> [a] -> [b]
mymap _ [] = [] -- if empty return empty
mymap f (x:xs) = f x : mymap f xs -- apply f and go next