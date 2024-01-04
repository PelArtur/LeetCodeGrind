"""
 https://leetcode.com/problems/determine-if-two-strings-are-close/?envType=study-plan-v2&envId=leetcode-75
"""

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:        
        chars1 = set(word1)
        chars2 = set(word2)
        
        word1CharOccurrences = [word1.count(chr) for chr in chars1]
        word2CharOccurrences = [word2.count(chr) for chr in chars2]
    
        return len(word1) == len(word2) and chars1 == chars2 and sorted(word1CharOccurrences) == sorted(word2CharOccurrences)
    
    
test1 = ["abc", "bca"]
test2 = ["a", "aa"]
test3 = ["cabbba", "abbccc"]

print(Solution().closeStrings(test1[0], test1[1]))
print(Solution().closeStrings(test2[0], test2[1]))
print(Solution().closeStrings(test3[0], test3[1]))


"""
 Main idea:
 
  Перевірити три пункти: чи розмір oбox стрічок є однаковим,
  обидві стрічки мають однаковий набір літер, значення входжень
  цих літер однаковий.
  
  З однаковим розміром інтуітивно зрозуміло, чому має виконуватись 
  ця умова.
  
  Однаковий набір літер:
  Якщо ми маємо слова "abc" та "abd", то вони не є наближено однаковими,
  оскільки за умовою ми можемо змінювати тільки присутні літери мід собою,
  aбo пересувати їх. Тобто не можна в першому слові замінити c на d, оскільки
  літери d немає y цьому слові.
  
  Однакові значення входжень
  Що таке значення входжень? Це список кількостей повторень кожної літери.
  Наприклад, маємо слово: "cabbba". To літери зустрічаються так:
    a -> 2
    b -> 3
    c -> 1
  Тоді масив [2, 3, 1] буде масивом кількості входжень літер y слові "cabbba".
  
  Чому вони мають співпадати?
  Розглянемо один із прикладів самого завдання: слова "cabbba" та = "abbccc".
  Літери зустрічаються таким чином:
    word1            word2
    a -> 2           a -> 1
    b -> 3           b -> 2
    c -> 1           c -> 3
  Якщо ми відсортуємо масиви кількості входжень, то в oбox випадках отримаємо ось
  це: [1, 2, 3]. Тому ми можемо перетосувати літери з одного слова так, щоб отримати
  інше. Спершу розташуємо літери в першому слові за кількостями входжень, як y другого
  та проведемо заміни літер
  
    cabbba -> три рази застосовуємо правило 1 для останньої a -> caabbb -> c на a ->
    -> accbbb -> b на c -> abbccc
    
  Тепер розглянемо приклад, де кількості входжень будуть різними: "ccabba" та = "abbccc"
    word1            word2
    a -> 2           a -> 1
    b -> 2           b -> 2
    c -> 2           c -> 3
  Отримали такі масиви кількості входжень: [2, 2, 2] та [1, 2, 3] для першого та другого 
  слова відповідно. Відсортуємо перше слово за лексикографічним порядком i подивимось на
  всі можливі варіанти перестановок літер:
  
  ccabba -> aabbcc -> ccaabb -> ccbbaa -> aaccbb -> bbccaa -> bbaacc
  
  Як можна побачити, жоден із 6 варіантів не є рівним другому слову. Отже, щоб перетворити
  одне слово на інше за допомогою 2 дозвоолених операцій, необхідно, щоб виконувались наступні
  три умови: однаковий розмір стрічок, однаковий набір літер, однакові значення входжень.
"""