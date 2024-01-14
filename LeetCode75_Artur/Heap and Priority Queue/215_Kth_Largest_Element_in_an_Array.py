"""
https://leetcode.com/problems/kth-largest-element-in-an-array/?envType=study-plan-v2&envId=leetcode-75
"""

from typing import Optional, List
import heapq

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        heap = nums[:k]
        heapq.heapify(heap)
        
        for i in range(k, len(nums)):
            if nums[i] > heap[0]:
                heapq.heappop(heap)
                heapq.heappush(heap, nums[i])
                
        return heap[0]
    
        
if (__name__ == '__main__'):
    solution = Solution()
    
    test1 = [3, 2, 1, 5, 6, 4]
    test2 = [3, 2, 3, 1, 2, 4, 5, 5, 6]
    
    print(solution.findKthLargest(test1, 2))
    print(solution.findKthLargest(test1, 1))
    print(solution.findKthLargest(test1, 6))
    print(solution.findKthLargest(test1, 4))
    
    print(solution.findKthLargest(test2, 2))
    print(solution.findKthLargest(test2, 1))
    print(solution.findKthLargest(test2, 9))
    print(solution.findKthLargest(test2, 4))
    
"""
Будуємо піраміду з k елементів. Основна ідея полягає в тому,
щоб у цій піраміді містити k найбільших елементів, а оскільки
нам потрібно знайти k-ий найбільший елемент, то ця піраміда буде
min-heap, тому на її вершині міститиметься необхідний елемент

Після того, як додали перших k елементів в піраміду запускаємо 
heapify, що отримати мінімальний елемент на вершині.

Починаємо ітеруватись з k елементу масиву і якщо цей елемент є більшим
за вершину піраміди, то вершину видаляємо з неї, а цей елемент пушимо
в піраміду.

У кінці в піраміді міститиметься k найбільших елементів, тому повертаємо
нульовий, який є найменшим серед них.

Часова складність: O(nlogn)
Додавання елементу в піраміду займає logn, а в найгіршому випадку ми цю 
операцію викличемо n разів, тома загальна складність алгоритму O(nlogn).

Також цікавий спосіб за O(n)

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        min_value = min(nums)
        max_value = max(nums)
        count = [0] * (max_value - min_value + 1)
        for num in nums:
            count[num - min_value] += 1

        remain = k
        for i in range(len(count) - 1, - 1, -1):
            remain -= count[i]
            if remain <= 0:
                return i + min_value
        return -1
        
Спершу шукаємо наймеший та найбільший елемент, створюємо масив, який
буде відповідати за кількість елементів певного значення в даному 
масиві, це масив містить max - min елементів.

Підраховуємо всі елементи, а дальше йдемо з кінця та віднімаємо кількість
входжень всіх елементів від k до тих пір, поки це значення не буде меншим 
або рівним k.

Яка проблема цієї реалзіації?
Якщо буде дуже велика різниця між мінімальним та максимальним значенням, то
масив для підрахунків входжень буде надто великим, а також якщо елементів у
заданому масиву буде мало, то це ще й займе дуже багато часу на обхід цього 
масиву, що по часу може програвати іншим реалізаціям.
Також виникнуть проблеми, якщо числа будуть не цілими.

Тому для підрахунку краще використовувати мапу.
"""