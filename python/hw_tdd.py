import unittest


class TestDrivenDevelopmentExample(unittest.TestCase):
    # Red
    #def test_red_sum(self):
       #self.assertEqual(sum([2, 3, 5, 7], 11), 13)

    # Green
    def test_green_sum(self):
        self.assertEqual(sum([2, 3, 5, 7], 11), 28)

    # Refactor
    def test_refactored_sum(self):
        for i in range(10):
            self.assertEqual(sum([1, 2, 3], i), 6+i)

if __name__ == '__main__':
    unittest.main()
