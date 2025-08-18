use itertools::Itertools;

struct Solution;

impl Solution {
    pub fn judge_point24(cards: Vec<i32>) -> bool {
        let cards: Vec<f64> = cards.into_iter().map(|c| c.into()).collect();

        assert_eq!(cards.len(), 4);

        let all_symbols = (1..=3)
            .map(|_i| {
                vec![
                    Symbol::Add,
                    Symbol::Subtract,
                    Symbol::Multiply,
                    Symbol::Divide,
                ]
            })
            // TODO: Can I code this?
            .multi_cartesian_product()
            .collect::<Vec<_>>();

        assert_eq!(all_symbols.len(), 4 * 4 * 4);

        for t in all_bin_trees(4) {
            for leaves in cards.clone().into_iter().permutations(4) {
                for symbols in &all_symbols {
                    if nearly_equal(24.0, eval(&t, &mut symbols.iter(), &mut leaves.iter())) {
                        // dbg!(&t, &symbols, &leaves);
                        return true;
                    }
                }
            }
        }

        false
    }
}

#[derive(Debug, Copy, Clone)]
enum Symbol {
    Add,
    Subtract,
    Multiply,
    Divide,
}

#[derive(Debug, Clone)]
enum BinTree {
    Leaf,
    NonLeaf {
        left: Box<BinTree>,
        right: Box<BinTree>,
    },
}

// TODO: Can we make this an iterator?
fn all_bin_trees(height: usize) -> Vec<BinTree> {
    match height {
        0 => Vec::new(),
        1 => vec![BinTree::Leaf],
        h => {
            let mut ret = Vec::new();

            for l in 1..=(h - 1) {
                let r = h - l;
                let lefts = all_bin_trees(l);
                let rights = all_bin_trees(r);

                for l_tree in &lefts {
                    for r_tree in &rights {
                        ret.push(BinTree::NonLeaf {
                            left: Box::new(l_tree.clone()),
                            right: Box::new(r_tree.clone()),
                        })
                    }
                }
            }

            ret
        }
    }
}

fn eval<'a>(
    t: &BinTree,
    symbols: &mut impl Iterator<Item = &'a Symbol>,
    leaves: &mut impl Iterator<Item = &'a f64>,
) -> f64 {
    match t {
        BinTree::Leaf => *leaves.next().unwrap(),
        BinTree::NonLeaf { left, right } => {
            let s = symbols.next().unwrap();
            let l = eval(left, symbols, leaves);
            let r = eval(right, symbols, leaves);
            match s {
                Symbol::Add => l + r,
                Symbol::Subtract => l - r,
                Symbol::Multiply => l * r,
                Symbol::Divide => l / r,
            }
        }
    }
}

const EPSILON: f64 = 1e-12;

fn nearly_equal(a: f64, b: f64) -> bool {
    (a - b).abs() < EPSILON
}

fn main() {
    assert_eq!(all_bin_trees(0).len(), 0);
    assert_eq!(all_bin_trees(1).len(), 1);
    assert_eq!(all_bin_trees(2).len(), 1);
    assert_eq!(all_bin_trees(3).len(), 2);
    assert_eq!(all_bin_trees(4).len(), 5);

    assert_eq!(
        (1..=3)
            .map(|_i| {
                vec![
                    Symbol::Add,
                    Symbol::Subtract,
                    Symbol::Multiply,
                    Symbol::Divide,
                ]
            })
            // TODO: Can I code this?
            .multi_cartesian_product()
            .collect::<Vec<_>>()
            .len(),
        4 * 4 * 4
    );

    assert!(Solution::judge_point24(vec![4, 1, 8, 7]));
    assert!(!Solution::judge_point24(vec![1, 2, 1, 2]));
    // assert_eq!(8.0 / (3.0 - (8.0 / 3.0)), 24.0);
    assert!(Solution::judge_point24(vec![3, 3, 8, 8]));
}
