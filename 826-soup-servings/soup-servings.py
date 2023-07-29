class Solution:
    def soupServings(self, n: int) -> float:
        def p(a_remaining, b_remaining, memo):
            if (a_remaining, b_remaining) in memo:
                return memo[(a_remaining, b_remaining)]

            if a_remaining <= 0 and b_remaining <= 0:
                return 0.5

            if a_remaining <= 0:
                return 1

            if b_remaining <= 0:
                return 0

            result = 0.25 * (
                p(a_remaining - 100, b_remaining, memo)
                + p(a_remaining - 75, b_remaining - 25, memo)
                + p(a_remaining - 50, b_remaining - 50, memo)
                + p(a_remaining - 25, b_remaining - 75, memo)
            )
            memo[(a_remaining, b_remaining)] = result
            return result

        memoization_dict = {}
        return 1 if n > 4450 else p(n, n, memoization_dict)
