import java.awt.EventQueue;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JButton;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTable;
import java.awt.Color;
import javax.swing.JScrollPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.border.BevelBorder;
import javax.swing.SwingConstants;
import javax.swing.JTextPane;
import java.awt.ComponentOrientation;

public class GUI {

	private JFrame frame;
	private JTable table;
	private JTable table_1;
	private JTable table_2;
	public List<List<Integer>> Imap;
	public List<List<String>> arrMap;
	public Object arrTable[][];
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					GUI window = new GUI();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public GUI() {
		initialize();
	}
	
	
	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		mapArray map = new mapArray();
		Imap = map.RetIArray();
		arrMap = map.arrString(Imap);
		
		frame = new JFrame();
		frame.setBounds(100, 100, 659, 547);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		
		JTabbedPane tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		tabbedPane.setBounds(0, 44, 653, 475);
		frame.getContentPane().add(tabbedPane);
		
		JPanel panel = new JPanel();
		tabbedPane.addTab("Main", null, panel, null);
		panel.setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(10, 36, 120, 351);
		panel.add(scrollPane);
		
		table = new JTable();
		Object[][] obstacle = map.FindObs(arrMap);
		String headerO [] = { "X", "Y"};
		table.setModel(new DefaultTableModel(obstacle, headerO));
		
		table.getColumnModel().getColumn(0).setPreferredWidth(45);
		table.getColumnModel().getColumn(1).setPreferredWidth(45);
		scrollPane.setViewportView(table);
		
		JLabel lblCo = new JLabel("OBSTACLE");
		lblCo.setHorizontalAlignment(SwingConstants.CENTER);
		lblCo.setFont(new Font("Arial", Font.BOLD, 12));
		lblCo.setBounds(10, 21, 120, 14);
		panel.add(lblCo);
		
		JLabel lblSurvivor = new JLabel("SURVIVOR");
		lblSurvivor.setHorizontalAlignment(SwingConstants.CENTER);
		lblSurvivor.setFont(new Font("Arial", Font.BOLD, 12));
		lblSurvivor.setBounds(506, 21, 120, 14);
		panel.add(lblSurvivor);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(506, 36, 120, 250);
		panel.add(scrollPane_1);
		
		table_1 = new JTable();
		Object[][] survivor = map.FindSuv(arrMap);
		String headerS [] = { "X", "Y"};
		table_1.setModel(new DefaultTableModel(survivor, headerS));
		
		table_1.getColumnModel().getColumn(0).setPreferredWidth(45);
		table_1.getColumnModel().getColumn(1).setPreferredWidth(45);
		scrollPane_1.setViewportView(table_1);
		
		JScrollPane scrollPane_2 = new JScrollPane();
		scrollPane_2.setBounds(140, 19, 354, 390);
		panel.add(scrollPane_2);
		
		table_2 = new JTable();
		table_2.setFont(new Font("Arial", table_2.getFont().getStyle(), table_2.getFont().getSize()));
		table_2.setBorder(new BevelBorder(BevelBorder.RAISED, Color.LIGHT_GRAY, null, null, null));
		Object[][] arrTable = map.ArrTableString(arrMap);
		String header [] = map.ArrHeader(arrMap);
		table_2.setModel(new DefaultTableModel( arrTable, header));
		
		
		for (int n = 0; n < arrMap.size(); n++) {
				table_2.getColumnModel().getColumn(n).setPreferredWidth(arrMap.get(n).size());
		}

		scrollPane_2.setColumnHeaderView(table_2);
		
		JTabbedPane tabbedPane_1 = new JTabbedPane(JTabbedPane.TOP);
		scrollPane_2.setViewportView(tabbedPane_1);
		
		JLabel lblSos = new JLabel("SOS BOARD");
		lblSos.setHorizontalAlignment(SwingConstants.CENTER);
		lblSos.setFont(new Font("Arial", Font.BOLD, 12));
		lblSos.setBounds(506, 295, 120, 28);
		panel.add(lblSos);
		
		JTextPane textPane = new JTextPane();
		textPane.setBounds(506, 319, 120, 81);
		panel.add(textPane);
		
		JPanel panel_1 = new JPanel();
		tabbedPane.addTab("Report 1", null, panel_1, null);
		
		JPanel panel_2 = new JPanel();
		tabbedPane.addTab("Report 2", null, panel_2, null);
		
		JLabel lblNavSys = new JLabel("NAV SYS");
		lblNavSys.setFont(new Font("Arial", Font.BOLD, 16));
		lblNavSys.setBounds(10, 11, 78, 22);
		frame.getContentPane().add(lblNavSys);
		
		
		JButton btnStop = new JButton("STOP");
		btnStop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textPane.setText("");
			}
		});
		btnStop.setBounds(564, 13, 73, 22);
		frame.getContentPane().add(btnStop);
				
		
		String SOSM = map.SOS(arrMap);
		textPane.setText(SOSM);
		
	}
}
