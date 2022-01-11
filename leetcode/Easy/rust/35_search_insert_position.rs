fn find_index<T: std::cmp::PartialEq, E>(arr: &Vec<T>, target: T) -> Result<usize, E> {
    return match Some(arr.iter().position(|r| r == &target).unwrap()) {
        Some(t) => Ok(t),
        None => Err(),
    }
}

fn main() {
    let nums = vec![1, 2, 3, 5, 6];
    let index = find_index(&nums, 2);
    println!("{:?}", index);
}