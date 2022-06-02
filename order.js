class Order{

    init(){
        this.order = []; // stroes the order ID for the customers
        this.priorities = []; // stores the priority value of the customers.
        this.total = 0; // tracks the number of customers in the queue.
    }

    addOrder(item, priority){
        
        if (this.order.length == 0){
            // when the order queue is empty.
            this.order.push(item);
            this.order.push(priority);
        } else {
            if (priority > this.priorities[this.total - 1]){
                // swap the last item with a higher priority value to restructure the queue. 
                let tempOrder = this.order[this.total - 1];
                this.order[this.total - 1] = item;
                this.order.push(tempOrder);

                let tempPriority = this.priorities[this.total - 1];
                this.priorities[this.total - 1] = priority;
                this.priorities.push(tempPriority);
            }
        }

    }

    deleteOrder(){
        this.order.pop();
        this.priorities.pop();
        this.total -= 1;
    }

    displayOrder(){
        for (let i = 0; i < this.total; i++){
            console.log(this.order[i] + " " + this.priorities[i]);
        }
    }

    calculatePriority(){
        
    }

}

class Customer{

    init(){
        this.firstName = "";
        this.lastName = "";
        this.mileage = 0;
        this.years = 0;
        this.sequence = 0;
    }

    setFirstName(firstName){
        this.firstName = firstName;
    }

    setLastName(lastName){
        this.lastName = lastName;
    }

    setMileage(mileage){
        this.mileage = mileage;
    }

    setYears(years){
        this.years = years;
    }

    setSequence(sequence){
        this.sequence = sequence;
    }

}

const orderClass = new Order();

document.getElementById("header-1").addEventListener("click", clearFunction);

const tag_text = document.getElementById("tag-text");

tag_text.addEventListener("click", myFunction);

function myFunction() {
  document.getElementById("demo").innerHTML = "Hello World";
}

function clearFunction(){
	document.getElementById("demo").innerHTML = "";
}

document.getElementById("order-btn").addEventListener("click", orderFunction);

function orderFunction(){
    let customer = new Customer();

    customer.setFirstName(document.getElementById("first-name-text").value);
    customer.setLastName(document.getElementById("last-name-text").value);
    customer.setMileage(document.getElementById("mileage-text").value);
    customer.setYears(document.getElementById("years-text").value);
    customer.setSequence(document.getElementById("sequence-text").value);

    orderClass.addOrder(customer, customer.sequence);

}

function cancelFunction(){

    orderClass.deleteOrder();

}