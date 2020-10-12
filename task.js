//click on x to delete entry
// alert("hello");

// $("input[type='text'").keypress(function(event){
// 	if(event.which === 13){
// 		var newEntry = $(this).val();
// 		$(this).val("");
// 		$("ul").append(
// 			"<li><span id='delete'><i class='fas fa-trash-alt'></i></span><span><i class='fas fa-angle-left'></i></span><span><i class='fas fa-angle-right'></i></span> "+newEntry+" </li>")
// 	}
// });


var arr = [ {num : 0, text : "Chapter1" , id : 1}, 
			{num : 0, text : "Chapter2" , id : 2},
			{num : 1, text : "Chapter3" , id : 3},
			{num : 2, text : "Chapter4" , id : 4},
			{num : 3, text : "Chapter5" , id : 5},
			{num : 2, text : "Chapter6" , id : 6},
			{num : 0, text : "Chapter7" , id : 7},
			{num : 1, text : "Chapter8" , id : 8} ];
// arr.push({num : 5, text : "task3" , id : 3});

var idx = 9;

function deleteHandler(event){
	console.log(event.target);
	let id = event.target.getAttribute("data-deleteid");
	let currIndex;
	arr.forEach(function(val , index){
		if(val.id == id){
			currIndex = index; 
		}
	});
	console.log(currIndex , id);
	//delete current
	let currentNum = arr[currIndex].num;
	let count = 1;
	//delete num[current] < num[i]	
	for(let i=currIndex+1 ; i<arr.length; i++){
		if(arr[i].num > currentNum){
			count++;
		}
		else{
			break;
		}
	}
	arr.splice(currIndex , count);
	render();
}

function indentHandler(event){
	console.log(event.target);
	let id = event.target.getAttribute("data-indentid");
	let currIndex;
	arr.forEach(function(val , index){
		if(val.id == id){
			currIndex = index; 
		}
	});
	console.log(currIndex , id);
	// count current
	let currentNum = arr[currIndex].num;
	if(currIndex != 0 && arr[currIndex-1].num >= arr[currIndex].num){
		arr[currIndex].num = currentNum+1;
		// let count = 1;
		// count num[current] < num[i]	
		for(let i=currIndex+1 ; i<arr.length; i++){
			if(arr[i].num > currentNum){
				arr[i].num = arr[i].num+1;
				// count++;
			}
			else{
				break;
			}
		}
	}
	render();
}

function outdentHandler(event){
	console.log(event.target);
	let id = event.target.getAttribute("data-outdentid");
	let currIndex;
	arr.forEach(function(val , index){
		if(val.id == id){
			currIndex = index; 
		}
	});
	console.log(currIndex , id);
	// count current
	let currentNum = arr[currIndex].num;
	if(currIndex != 0){
		arr[currIndex].num = currentNum-1;
		// let count = 1;
		// count num[current] < num[i]	
		for(let i=currIndex+1 ; i<arr.length; i++){
			if(arr[i].num > currentNum){
				arr[i].num = arr[i].num-1;
				// count++;
			}
			else{
				break;
			}
		}
	}
	render();
}

function render(){
	var taskList = document.getElementById("taskList");
	taskList.innerHTML = "";
	arr.forEach(function(val){
		var div = document.createElement("div");
		div.textContent = val.text;
		div.style.paddingLeft = 25*val.num + "px";
		div.innerHTML = 
		`<div><span id="delete"><span class="deleteHover">Delete</span><i class="deleteColour fas fa-trash-alt" id="delete${val.id}" data-deleteid="${val.id}"></i></span><span id="indentHover"><span class="deleteHover">Outdent</span><i class="outdentColour fas fa-angle-left" id="outdent${val.id}" data-outdentid="${val.id}"></i></span><span id="outdentHover"><span class="deleteHover">Indent</span><i class="indentColour fas fa-angle-right" id="indent${val.id}" data-indentid="${val.id}"></i></span><span class="textClass">${val.text}</span></div>`
		taskList.appendChild(div);	
		let deletebtn = document.getElementById(`delete${val.id}`);
		deletebtn.addEventListener("click" , deleteHandler);
		let indentbtn = document.getElementById(`indent${val.id}`);
		indentbtn.addEventListener("click" , indentHandler);
		let outdentbtn = document.getElementById(`outdent${val.id}`);
		outdentbtn.addEventListener("click" , outdentHandler);
		
	});
}

var input = document.getElementById("input");
input.addEventListener("keypress" , function(event){
	if(event.which==13){
		// console.log("h",event.target.value);
		arr.push({num : arr.length-1>=0?arr[arr.length-1].num:0 , text : event.target.value , id : idx});
		// var div = document.createElement("div");
		// div.textContent = event.target.value;
		// div.innerHTML = 
		// `<div id="rmv" data-deleteid="${idx}"><span id="delete"><i class="fas fa-trash-alt"></i></span><span><i class="fas fa-angle-left"></i></span><span><i class="fas fa-angle-right"></i></span><span>${event.target.value}</span></div>`
		idx++;
		// div.style.paddingLeft = 10*arr[arr.length-1].num + "px";
		// taskList.appendChild(div);
		event.target.value = "";
		render();
	}
});

// $("div").on("click","#rmv",function(event){
// 	$(this).fadeOut(500,function(){
// 		$(this).remove();
// 	});
// 	event.stopPropagation();
// });

$(".fa-plus").click(function(){
	$("input[type='text'").fadeToggle()
});

render();


