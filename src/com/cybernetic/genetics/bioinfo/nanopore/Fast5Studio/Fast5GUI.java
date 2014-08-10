package com.cybernetic.genetics.bioinfo.nanopore.Fast5Studio;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;

public class Fast5GUI extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	Fast5GUI(){
		this.setTitle("Fast5 Studio");
		this.setExtendedState(MAXIMIZED_BOTH);
		createMenu();
		setVisible(true);
	}
	
	/**
	 * create menu elements
	 */
	private void createMenu(){
		JMenuBar mainMenu = new JMenuBar();
		
		mainMenu.add(fileMenu());
		mainMenu.add(statsMenu());
		mainMenu.add(optionsMenu());
		
		this.setJMenuBar(mainMenu);
	}

	private JMenu optionsMenu() {
		JMenu optionsmenu = new JMenu("Options");
		//FIXME add menu elements here
		return optionsmenu;
	}

	private JMenu statsMenu() {
		JMenu statmenu = new JMenu("Statistics");
		//FIXME add menu elements here
		return statmenu;
	}

	private JMenu fileMenu() {
		JMenu filemenu = new JMenu("File");
		
		filemenu.add(openFileMenu());
		filemenu.add(openDirMenu());
		filemenu.addSeparator();
		filemenu.add(saveFastQMenu());
		filemenu.add(saveFastaMenu());
		filemenu.addSeparator();
		filemenu.add(exitMenu());
		
		return filemenu;
	}

	private JMenuItem exitMenu() {
		JMenuItem exit = new JMenuItem("Exit");
		exit.addActionListener(new ActionListener(){

			@Override
			public void actionPerformed(ActionEvent e) {
				setVisible(false);
				dispose();
			}
			
		});
		return exit;
	}

	private JMenuItem saveFastaMenu() {
		JMenuItem savefasta = new JMenuItem("Export FASTA...");

		return savefasta;
	}

	private JMenuItem saveFastQMenu() {
		JMenuItem savefastq = new JMenuItem("Export FASTQ...");
		
		return savefastq;
	}

	private JMenuItem openDirMenu() {
		JMenuItem opendir = new JMenuItem("Open dir...");
		
		return opendir;
	}

	private JMenuItem openFileMenu() {
		JMenuItem openfile = new JMenuItem("Open...");
		
		return openfile;
	}
}
