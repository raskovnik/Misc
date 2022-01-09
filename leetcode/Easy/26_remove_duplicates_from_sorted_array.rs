fn remove_duplicates(nums: &mut Vec<i32>) {
    let mut temp = Vec::new();
    for i in nums.iter() {
        if !temp.contains(i) {
            temp.push(*i);
        }
    }

    println!("{:?}", temp);
}

fn main() {
    let mut nums = vec![0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5];
    remove_duplicates(&mut nums);

}