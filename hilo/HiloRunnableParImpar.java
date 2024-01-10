public class HiloRunnableParImpar implements Runnable {
    private String nombre;

    @Override
    public void run() {
        Thread.currentThread().setName(nombre);
        if (nombre.equals("XX")){
            //Thread.currentThread().setName(nombre);
            for (int i = 2; i <= 100; i = i+2) {
                System.out.println("Hilo:" + Thread.currentThread().getName() + " generando número par = " + i);
            }
        }else{
            //Thread.currentThread().setName(nombre);
            for (int i = 101; i <= 200 ; i = i+2) {
                System.out.println("Hilo:" + Thread.currentThread().getName() + " generando número impar = " + i);
            }
        }
    }

    public HiloRunnableParImpar(String name) {
        this.nombre = name;
    }

}
