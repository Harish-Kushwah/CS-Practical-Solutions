
package sem6.Java.practicals.slip0;

import java.util.*;

class Student implements Comparator<Student>, Comparable<Student> {
    int roll_num;
    String name;

    Student(int roll_num, String name) {
        this.roll_num = roll_num;
        this.name = name;

    }

    Student() {
    }

    @Override
    public int compareTo(Student student) {

        // return (this.name).compareTo(student.name); // 23 - 25 => - 2
        return this.roll_num - student.roll_num;

    }

    @Override
    public int compare(Student s1, Student s2) {
        // return s2.roll_num -s1.roll_num ;
        return (s1.name).compareTo(s2.name);
    }

    @Override
    public String toString() {
        return this.name + " " + this.roll_num;
    }

}
// s1 s2
// harish pratik

// 1 2 3 4
// 3 -1 = 2 +ve no swap
// 2 -1 = 1 +ve no swap
// 4-1 = 3 +ve no swap
// 2-3 = -1 -ve swap
public class Sample {
    public static void main(String[] args) {
        List<Student> list = new ArrayList<>();

        list.add(new Student(10, "a"));
        list.add(new Student(11, "c"));
        list.add(new Student(1, "b"));

        Collections.sort(list);

        System.out.println(list);

        Collections.sort(list, new Student());

        System.out.println(list);

        // method1 : for traversing
        for (int i = 0; i < list.size(); i++) {
            System.out.println(list.get(i));
        }

        // foreach
        for (Student student : list) {
            System.out.println(student);
        }

        Iterator itr = list.iterator();

        while (itr.hasNext()) {
            System.out.println(itr.next());
        }

        // 1 2 3 4

        System.out.println("using list iterator");

        ListIterator list_itr = list.listIterator(list.size());

        // while (list_itr.hasNext()) {
        // list_itr.next();
        // }
        while (list_itr.hasPrevious()) {
            System.out.println(list_itr.previous());
        }

        // enumrations

        Vector<String> li = new Vector<>();

        li.add("harihs");
        li.add("Pratik");
        li.add("abc");
        Enumeration enm = li.elements();
        while (enm.hasMoreElements()) {
            System.out.println(enm.nextElement());
        }

    }
}
