class PrintArgs {

	static void main(String[] args){

		/*
		IO.println(args[0]);
		*/

		if (args.length <= 0){
			IO.println("Passer un argument !!!");
			return;
		}

		/*
		int i;
		for(i = 0; i < args.length; i++){
			IO.println(args[i]);
		}
		*/
		for(var element : args){
			IO.println(element);
		}
	}
}