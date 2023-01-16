let pesofruta=[1000, 1500, 2000, 5000, 500];
let preciofruta=[2.50, 1.75, 1.55, 2.70, 1.25];
let caja=0.0, kg_venta=0;
let opcion=0, cod_fruta=0, n=5;
let fruta=["manzanas","peras", "platanos", "fresas", "sandias"];
let repetir='Y';

document.addEventListener("keydown", e => {
switch(e.key){
    case "1":
        op_1();
        break;
    case "2":
        op_2();
        break;
    case "3":
        op_3();
        break;
    case "4":
        op_4();
        break;
    case "5":
        op_5();
        break;
    case "6":
        op_6();
        break;
    default:
        break;
}
});

/* 
const newh2 = document.createElement("h2");
const newp = document.createElement("p");
let node = document.createTextNode("New node"); 
*/

function op_1(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 1. Vender Fruta";
}

function op_2(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 2. Consultar Caja";
}

function op_3(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 3. Reponer Stock Almacen";
}

function op_4(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 4. Consultar Stock Actual";
}

function op_5(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 5. Editar precios";
}

function op_6(){
    let title = document.getElementById("nombre_opcion");
    title.innerHTML = "Caso 6. Salir";
}