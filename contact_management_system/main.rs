use std::io;

#[derive(Debug)]
struct Contact {
    fname: String,
    lname: String, 
    address: String,
    contact: String,
    email: String,
}

impl Contact {
    fn edit(&mut self, field: String, new_value: String) {
        match field {
            fname => self.fname = new_value,
            lname => self.lname = new_value,
            address => self.address = new_value,
            contact => self.contact = new_value,
            email => self.email = new_value,
            _ => println!("Field does not exist")
        }
    }
}

fn get_input(input_message: &str) -> String {
    println!(input_message);
    let input = io::stdin().read_line();
    return input;

}

fn print_menu() {
    println!("[1] Add a new contact");
    println!("[2] List all contacts");
    println!("[3] Search for contact");
    println!("[4] Edit a contact");
    println!("[5] Delete a contact");
    println!("[0] Exit");
}


fn main() {
    print_menu();
    println!("Enter your choice: ");
    let choice = io::stdin().read_line().parse().expect("Expected an integer");
    match choice {
        1 => {
            let mut contact = Contact {
            fname: get_input("Enter your first name: "),
            lname: get_input("Enter your last name: "), 
            address: get_input("Enter your address: "),
            contact: get_input("Enter your contact: "),
            email: get_input("Enter your email"),
            };
            println!("{:?}", contact);
        }
        _ => println!("Invalid choice!");
    }


}