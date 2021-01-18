function gcd(a,b){
    console.log(a.toString()+" "+b.toString()+"\n");
    if(a==0)
        return b;
    return gcd(b%a,a);
}
var additional_fields=0;
inputs=document.getElementById("inputs");
add_field=document.getElementById("add_bt");
result_field=document.getElementById("results");
calc_button=document.getElementById("submit_bt");
if(add_field==null){
    console.log("NULL FIELD!");
}
snippet='<input type="number" id="num1">'
add_field.addEventListener("click",function(){
    additional_fields++;
    inputs.innerHTML+='<input type="number" id="num'+(additional_fields+2).toString()+'">'
});
calc_button.addEventListener("click",function(){
    numbers=[] 
    for(i=0;i<2+additional_fields;i++){
        try{
            console.log("\n");
            console.log("\nnum"+(i+1).toString()+"\n");
            console.log(parseInt(document.getElementById("num"+(i+1).toString()).value));
            if(isNaN(parseInt(document.getElementById("num"+(i+1).toString()).value))){
                alert("Input is not an integer!");
                location.reload();
                return;
            }
            num=parseInt(document.getElementById("num"+(i+1).toString()).value);
            if(num==0){
                alert("Invalid Number Entered! Enter any integers other than 0");
                location.reload();
                additional_fields=0;
                return;
            }
            if(num<0)
                num=-num;
            numbers.push(num);
        }
        catch(e){
            alert("Invalid Input Format")
         }
    }
    result=numbers[0];
    console.log(numbers.length);
    result_field.innerText="The GCD of "+numbers[0].toString();
    for(i=1;i<numbers.length;i++){
        result=gcd(result,numbers[i]); 
        result_field.innerText+=","+numbers[i].toString();
    }
    result_field.innerText+=" is "+result.toString();
});