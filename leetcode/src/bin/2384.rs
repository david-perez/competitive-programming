struct Solution;

impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut ret = 0;
        let mut cur = 0;

        for x in nums {
            if x == 0 {
                cur += 1;
            } else {
                ret += (cur * (cur + 1)) / 2;
                cur = 0;
            }
        }

        ret += (cur * (cur + 1)) / 2;
        ret
    }
}

fn main() {
    assert_eq!(
        6,
        Solution::zero_filled_subarray(vec![1, 3, 0, 0, 2, 0, 0, 4])
    );
    assert_eq!(9, Solution::zero_filled_subarray(vec![0, 0, 0, 2, 0, 0]));
    assert_eq!(0, Solution::zero_filled_subarray(vec![2, 10, 2019]));
}
